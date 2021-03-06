#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(set = 0, binding = 0) uniform UboScene 
{
	mat4 projection;
	mat4 view;
	vec4 clip;
} scene;

layout(set = 0, binding = 1) uniform UboObject 
{
	mat4 transform;
	vec4 skyColour;
	vec4 fogColour;
	vec2 fogLimits;
	float blendFactor;
} object;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUv;
layout(location = 2) in vec3 vertexNormal;
layout(location = 3) in vec3 vertexTangent;

layout(location = 0) out vec3 fragmentUv;
layout(location = 1) out float fragmentHeight;

out gl_PerVertex 
{
	vec4 gl_Position;
	float gl_ClipDistance[];
};

void main() 
{
	vec4 worldPosition = object.transform * vec4(vertexPosition, 1.0f);
	
    gl_Position = scene.projection * scene.view * worldPosition;
	gl_ClipDistance[0] = dot(worldPosition, scene.clip);
	
	fragmentUv = vertexPosition;
	fragmentHeight = worldPosition.y;
}
