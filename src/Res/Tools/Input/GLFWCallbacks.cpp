#include "GLFWCallbacks.h"


void GLAPIENTRY MessageCallback(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam){
	std::string errorDetails = "Other Error";
	if(type == GL_DEBUG_TYPE_ERROR)
		errorDetails = "General Error";
	else if(type == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR)
		errorDetails = "Deprecated Behavior Error";
	else if(type == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR)
		errorDetails = "Undefined Behavior Error";
	else if(type == GL_DEBUG_TYPE_PORTABILITY)
		errorDetails = "Portability Error";
	else if(type == GL_DEBUG_TYPE_PERFORMANCE)
		errorDetails = "Performance Error";

	std::string errorSource = "Other source";
	if(source == GL_DEBUG_SOURCE_API)
		errorSource = "OpenGL API";
	else if(source == GL_DEBUG_SOURCE_WINDOW_SYSTEM)
		errorSource = "Window-Systems API";
	else if(source == GL_DEBUG_SOURCE_SHADER_COMPILER)
		errorSource = "Shader Compiler";
	else if(source == GL_DEBUG_SOURCE_THIRD_PARTY)
		errorSource = "Third-Party OpenGL";
	else if(source == GL_DEBUG_SOURCE_APPLICATION)
		errorSource = "Vofog";

	if(severity == GL_DEBUG_SEVERITY_HIGH){//ignore pedantic errors/msgs
		ERROR("OpenGL %s\tSeverity: HIGH. \t ID: %d\n\t%s\n", errorDetails.c_str(), id, message);
	}
	if(severity == GL_DEBUG_SEVERITY_MEDIUM){//ignore pedantic errors/msgs
		ERROR("OpenGL %s\tSeverity: Medium. \t ID: %d\n\t%s\n", errorDetails.c_str(), id, message);
	}
	if(severity == GL_DEBUG_SEVERITY_LOW){//ignore pedantic errors/msgs
		//ERROR("OpenGL " << errorDetails << "\tSeverity: Low. \t ID: " << id << "\n\t\"" << message << "\"\n");
	}
}

void GLFWCallbacks::initCallBacks(res::Window* _windowRef){
	glfwSetKeyCallback(_windowRef->getWindow(), GLFWCallbacks::keyCallback);
	glfwSetCursorPosCallback(_windowRef->getWindow(), GLFWCallbacks::cursorPositionCallback);
	glfwSetMouseButtonCallback(_windowRef->getWindow(), GLFWCallbacks::mouseClickCallback);
	int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
	if (flags & GL_CONTEXT_FLAG_DEBUG_BIT){
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); 
		glDebugMessageCallback(MessageCallback, 0);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	} 

	glDebugMessageControl(GL_DEBUG_SOURCE_API, 
                      GL_DEBUG_TYPE_ERROR, 
                      GL_DEBUG_SEVERITY_HIGH,
                      0, nullptr, GL_TRUE); 

}
void GLFWCallbacks::mouseClickCallback(GLFWwindow* window, int button, int action, int mods) {
	static uint16_t mouseKey;
	mouseKey = res::MouseKeys::MOUSE_BUTTON_1;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = res::MouseKeys::MOUSE_BUTTON_2;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = res::MouseKeys::MOUSE_BUTTON_3;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = res::MouseKeys::MOUSE_BUTTON_4;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = res::MouseKeys::MOUSE_BUTTON_5;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}
	mouseKey = res::MouseKeys::MOUSE_BUTTON_6;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = res::MouseKeys::MOUSE_BUTTON_7;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

	mouseKey = res::MouseKeys::MOUSE_BUTTON_8;
	if (button == mouseKey && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		res::InputManager::addMousePress(mouseKey);
	}
	if (button == mouseKey && action == GLFW_RELEASE) {
		res::InputManager::addMouseRelease(mouseKey);
	}

}


void GLFWCallbacks::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	static uint16_t keyCheck;
	keyCheck = res::KeyCodes::KEY_SPACE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_APOSTROPHE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_COMMA; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_MINUS; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_PERIOD; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_SLASH; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_0; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_3; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_4; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_5; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_6; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_7; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_8; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_9; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_SEMICOLON; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_EQUAL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_A; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_B; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_C; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_D; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_E; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_G; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_H; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_I; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_J; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_K; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_L; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_M; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_N; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_O; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_P; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_Q; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_R; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_S; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_T; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_U; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_V; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_W; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_X; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_Y; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_Z; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_LEFT_BRACKET; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_BACKSLASH; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_RIGHT_BRACKET; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_GRAVE_ACCENT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_WORLD_1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_WORLD_2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_ESCAPE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_ENTER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_TAB; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_BACKSPACE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_INSERT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_DELETE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_RIGHT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_LEFT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_DOWN; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_UP; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_PAGE_UP; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_PAGE_DOWN; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_HOME; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_END; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_CAPS_LOCK; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_SCROLL_LOCK; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_NUM_LOCK; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_PRINT_SCREEN; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_PAUSE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F3; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F4; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F5; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F6; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F7; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F8; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F9; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F10; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F11; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F12; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F13; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F14; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F15; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F16; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F17; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F18; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F19; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F20; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F21; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F22; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F23; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F24; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_F25; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_0; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_1; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_2; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_3; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_4; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_5; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_6; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_7; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_8; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_9; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_DECIMAL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_DIVIDE; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_MULTIPLY; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_SUBTRACT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_ADD; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_ENTER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_KP_EQUAL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_LEFT_SHIFT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_LEFT_CONTROL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_LEFT_ALT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_LEFT_SUPER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_RIGHT_SHIFT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_RIGHT_CONTROL; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_RIGHT_ALT; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_RIGHT_SUPER; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }
	keyCheck = res::KeyCodes::KEY_MENU; if (key == keyCheck && (action == GLFW_PRESS || action == GLFW_REPEAT)) { res::InputManager::addKeyPress(keyCheck); }	if (key == keyCheck && action == GLFW_RELEASE) { res::InputManager::addKeyRelease(keyCheck); }


}

void GLFWCallbacks::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	res::InputManager::addMousePosition(xpos, ypos);
}