#pragma once

namespace Core {
	class Window {
	private:
		int width;
		int height;
	public:
		Window(int width, int height);
		virtual ~Window();
		void setSize(int width, int height);
		

		virtual void init() = 0;

		virtual void close() = 0;
	};
}