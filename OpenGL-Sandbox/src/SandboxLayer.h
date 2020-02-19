#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

#include "ParticleSystem.h"

class SandboxLayer : public GLCore::Layer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(GLCore::Event& event) override;
	virtual void OnUpdate(GLCore::Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
	GLCore::Utils::OrthographicCameraController m_CameraController;
	ParticleProps m_Particle;
	ParticleSystem m_ParticleSystem;
};