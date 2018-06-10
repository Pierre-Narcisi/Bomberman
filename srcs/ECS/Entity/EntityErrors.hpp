/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Errors.hpp
*/

#include <exception>
#include <string>

namespace ecs { namespace entity {

	class EntityError : public std::exception {
	};

	class BadEntityError : public EntityError {
	public:
		BadEntityError() throw() :
		_msg("EntityManger : fail to access an entity") {}

		char const *what() const throw() override {
			return (_msg.c_str());
		}

		virtual ~BadEntityError() throw(){}

	private:
		std::string _msg;
	};

}}