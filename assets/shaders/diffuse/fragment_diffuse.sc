$input v_normal, v_color0

#include "../common.sc"

void main()
{
    // Normalize the normal
    vec3 normal = normalize(v_normal);

    // Light direction (example: light coming from the top-right-front)
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));

    // Lambertian diffuse lighting
    float diff = max(dot(normal, lightDir), 0.0);

    // Apply the lighting to the color
    vec4 color = v_color0 * diff;

    gl_FragColor = color;
}