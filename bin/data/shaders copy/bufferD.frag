void mainImage( out vec4 fragColor, in vec2 fragCoord ) {
    vec2 uv = fragCoord/iResolution.xy;
    float r = 0.96 * texture(iChannel3, uv).x;
    if (texture(iChannel2, uv).x > 0.) r = 1.;
    fragColor.x = r;
}