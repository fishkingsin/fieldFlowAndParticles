//2D Vector field visualizer by nmz (twitter: @stormoid)

/*
	There is already a shader here on shadertoy for 2d vector field viz, 
	but I found it to be hard to use so I decided to write my own.
*/


#define time iTime
uniform int vector_mode;
uniform float arrow_density;
uniform float arrow_length;

uniform int iterationTime1;
uniform int iterationTime2;
uniform float scale;

uniform float velocity_x;
uniform float velocity_y;

uniform float mode_2_speed;
uniform float mode_1_detail;
uniform float mode_1_twist;

uniform bool isArraw;

// Parameterized uniforms for mode 1 color (was hard-coded)
uniform float mode1_phase;    // default 1.0 (phase added to p.x+p.y for R,G)
uniform float mode1_rg_amp;   // default 0.5 (amplitude for R,G)
uniform float mode1_rg_bias;  // default 0.5 (bias for R,G)
uniform float mode1_b_amp;    // default 0.3 (amplitude for B)
uniform float mode1_b_bias;   // default 0.5 (bias for B)

const vec3 luma = vec3(0.2126, 0.7152, 0.0722);
const vec3 baseColor = vec3(0.2126, 0.7152, 1);


float f(in vec2 p)
{
    return sin(p.x+sin(p.y+time*velocity_x)) * sin(p.y*p.x*0.1+time*velocity_y);
}


struct Field {
    vec2 vel;
    vec2 pos;
};

//---------------Field to visualize defined here-----------------

Field field(in vec2 p,in int mode)
{
    Field field;
    if(mode == 0){
    	vec2 ep = vec2(0.05,0.);
        vec2 rz= vec2(0);
        //# centered grid sampling
        for( int i=0; i<iterationTime1; i++ )
        {
            float t0 = f(p);
            float t1 = f(p + ep.xy);
            float t2 = f(p + ep.yx);
            vec2 g = vec2((t1-t0), (t2-t0))/ep.xx;
            vec2 t = vec2(-g.y,g.x);
            
            //# need update 'p' for next iteration,but give it some change.
            p += (mode_1_twist*0.01)*t + g*(1./mode_1_detail);
            p.x = p.x + sin( time*mode_2_speed/10.)/10.;
            p.y = p.y + cos(time*mode_2_speed/10.)/10.;
            rz= g; 
        }
        field.vel = rz;
        return field;
    }
    
    if(mode == 1){
        vec2 ep = vec2(0.05,0.);
        vec2 rz= vec2(0);
        //# centered grid sampling
        for( int i=0; i<iterationTime1; i++ )
        {
            float t0 = f(p);
            float t1 = f(p + ep.xy);
            float t2 = f(p + ep.yx);
            vec2 g = vec2((t1-t0), (t2-t0))/ep.xx;
            vec2 t = vec2(-g.y,g.x);

            //# need update 'p' for next iteration,but give it some change.
            p += (mode_1_twist*0.01)*t + g*(1./mode_1_detail);
            p.x = p.x + sin( time*mode_2_speed/10.)/10.;
            p.y = p.y + cos(time*mode_2_speed/10.)/10.;
            rz= g;
        }
        
        field.vel = rz;
        // add curved effect into curved mesh
        for(int i=1; i<iterationTime2; i++){
            //# try comment these 2 lines,will give more edge effect
            p.x+=0.3/float(i)*sin(float(i)*3.*p.y+time*mode_2_speed) + 0.5;
            p.y+=0.3/float(i)*cos(float(i)*3.*p.x + time*mode_2_speed) + 0.5;
        }
        field.pos = p;
        return field;
    }
    
    return field;
}
//---------------------------------------------------------------

float segm(in vec2 p, in vec2 a, in vec2 b) //from iq
{
	vec2 pa = p - a;
	vec2 ba = b - a;
	float h = clamp(dot(pa,ba)/dot(ba,ba), 0., 1.);
	return length(pa - ba*h)*20.*arrow_density;
}

float fieldviz(in vec2 p,in int mode)
{
    vec2 ip = floor(p*arrow_density)/arrow_density + .5/arrow_density;   
    vec2 t = field(ip,mode).vel;
    float m = min(0.1,pow(length(t),0.5)*(arrow_length/arrow_density));
    vec2 b = normalize(t)*m;
    float rz = segm(p, ip, ip+b);
    vec2 prp = (vec2(-b.y,b.x));
    rz = min(rz,segm(p, ip+b, ip+b*0.65+prp*0.3));
    return clamp(min(rz,segm(p, ip+b, ip+b*0.65-prp*0.3)),0.,1.);
}


vec3 getRGB(in Field fld,in int mode){

    if(mode == 0){
        vec2 p = fld.vel;
        vec3 origCol = vec3(p * 0.5 + 0.5, 1.5);
        return origCol;
    }
    
    if(mode == 1){
        vec2 p = fld.pos;
        float sum = p.x + p.y;
        // Parameterized version of original:
        // r=cos(sum+1.)*0.5+0.5
        // g=sin(sum+1.)*0.5+0.5
        // b=(sin(sum)+cos(sum))*0.3+0.5
        float r = cos(sum + mode1_phase) * mode1_rg_amp + mode1_rg_bias;
        float g = sin(sum + mode1_phase) * mode1_rg_amp + mode1_rg_bias;
        float b = (sin(sum) + cos(sum)) * mode1_b_amp + mode1_b_bias;
        return vec3(r,g,b);
    }

}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	vec2 p = fragCoord.xy / iResolution.xy-0.5 ;
	p.x *= iResolution.x/iResolution.y;
    p *= scale;
    
    vec2 uv = fragCoord.xy / iResolution.xy;
    vec3 col;
    float fviz;
    
    // int vector_mode = 0;
    // if(uv.x > slideValX){
    //     vector_mode = 1;
    // }

    //vec2 fld = field(p,vector_mode).vel;
    //col = sin(vec3(-.3,0.1,0.5)+fld.x-fld.y)*0.65+0.35;
    Field fld = field(p,vector_mode);
    col = getRGB(fld,vector_mode) * 0.85;
    fviz = fieldviz(p,vector_mode);
    
    if(isArraw == true){
        #if 1
        col = max(col, 1.-fviz*vec3(1.));
        #else
        if (dot(luma,col) < 0.5)
            col = max(col, 1.-fviz*vec3(1.));
        else
            col = min(col, fviz*vec3(1.));
        #endif
    }
    
	fragColor = vec4(col,1.0);
}
