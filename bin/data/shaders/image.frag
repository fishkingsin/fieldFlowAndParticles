#define TESTING 0
void mainImage( out vec4 fragColor, in vec2 fragCoord ) {
	vec2 uv = fragCoord;
	vec4 texCol = texture(iChannel0,uv);
	
	float r = texture(iChannel3, uv).x;
	//r = 0.9 - 0.8 * r;
	fragColor = vec4(vec3(r,r,r)*texCol.rgb, 1);
	if (TESTING==1){
		if(uv.x<slideValX && uv.y>slideValY){
			fragColor = texture(iChannel0, uv);
		}
		
		if(uv.x>slideValX && uv.y>slideValY){
			fragColor = texture(iChannel1, uv);
		}
		
		if(uv.x<slideValX && uv.y<slideValY){
			fragColor = texture(iChannel3, uv);
		}
		
		if(uv.x>slideValX && uv.y<slideValY){
			fragColor = texture(iChannel2, uv);
		}
	}
	
	
	
}
