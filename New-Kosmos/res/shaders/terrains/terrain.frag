#version 450
#extension GL_ARB_separate_shader_objects : enable

//---------IN------------
flat in vec3 pass_normal;
flat in vec3 pass_colour;

//---------OUT------------
layout(location = 0) out vec4 out_albedo;
layout(location = 1) out vec4 out_normals;
layout(location = 2) out vec4 out_extras;

uniform float shineDamper;
uniform float reflectivity;

//---------MAIN------------
void main(void) {
	out_albedo = vec4(pass_colour, 1.0);
	out_normals = vec4(pass_normal + 1.0 / 2.0, out_albedo.a);
	out_extras = vec4(shineDamper, reflectivity, 0.0, out_albedo.a);
}