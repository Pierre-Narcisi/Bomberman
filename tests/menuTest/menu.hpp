#pragma once

#include <string>
#include <list>
#include <iostream>

namespace menu {

	class Menu {

		public:

			Menu() = default;
			~Menu() = default;
			void setRoot(std::string const &);
			void push(std::string const &);
			void pop();
			void viewCtrl();

		private:

			std::list<std::string> _menu;
	};

}
