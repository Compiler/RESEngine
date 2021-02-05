#include "StartupSystem.h"



namespace res{

	void StartupSystem::_initGLFW(){
		if(!glfwInit()){ INIT_LOG("Failed to init glfw");}
		else { INIT_LOG("GLFW initialized."); }
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);//version 4.6 Core profile
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true); 

		//glfwWindowHint( GLFW_DOUBLEBUFFER, GL_FALSE );
		glfwSwapInterval( 0 );


	}
	void StartupSystem::_initGlad(){
		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){ERROR("Failed to init glad");}
		else { INIT_LOG("Glad initialized."); }


		glEnable(GL_BLEND); 
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
	

	}


	void StartupSystem::_initImGUI(GLFWwindow* window){
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui_ImplOpenGL3_Init("#version 460");
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui::StyleColorsDark();
	}

	void StartupSystem::initSubSystems(){
			_initGLFW();
			_initGlad();
	}

}