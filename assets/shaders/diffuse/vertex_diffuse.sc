$input a_position, a_normal, a_color0
$output v_color0

#include "../common.sc"

void main()
{
    vec4 pos = vec4(a_position, 1.0);
    gl_Position = mul(u_modelViewProj, pos);

    v_normal = mul(u_model, vec4(a_normal, 0.0)).xyz;
    v_color0 = a_color0;
}