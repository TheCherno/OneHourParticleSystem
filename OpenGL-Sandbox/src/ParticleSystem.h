#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

struct ParticleProps
{
	glm::vec2 Position;
	glm::vec2 Velocity, VelocityVariation;
	glm::vec4 ColorBegin, ColorEnd;
	float SizeBegin, SizeEnd, SizeVariation;
	float LifeTime = 1.0f;
};

class ParticleSystem
{
public:
	ParticleSystem();

	void OnUpdate(GLCore::Timestep ts);
	void OnRender(GLCore::Utils::OrthographicCamera& camera);

	void Emit(const ParticleProps& particleProps);
private:
	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity;
		glm::vec4 ColorBegin, ColorEnd;
		float Rotation = 0.0f;
		float SizeBegin, SizeEnd;

		float LifeTime = 1.0f;
		float LifeRemaining = 0.0f;

		bool Active = false;
	};
	std::vector<Particle> m_ParticlePool;
	uint32_t m_PoolIndex = 999;

	GLuint m_QuadVA = 0;
	std::unique_ptr<GLCore::Utils::Shader> m_ParticleShader;
	GLint m_ParticleShaderViewProj, m_ParticleShaderTransform, m_ParticleShaderColor;
};