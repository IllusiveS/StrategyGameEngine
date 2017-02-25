//
// Created by wysockipatryk on 2/25/17.
//

#ifndef STRATEGYGAME_MODULE_H
#define STRATEGYGAME_MODULE_H

#include <string>
#include <GameElements/BasicElement.h>
#include "json/json.hpp"

using json = nlohmann::json;

namespace BaseModel {
	class Module : public BasicElement{
	protected:
		std::string name;
		std::string author;
		std::string description;
	public:
		Module();
	public:
		const std::string &getName() const;
		void setName(const std::string &name);

		const std::string &getAuthor() const;
		void setAuthor(const std::string &author);

		const std::string &getDescription() const;
		void setDescription(const std::string &description);

	public:
		virtual json serializeToJson() override;
	};

	struct ModuleCreationParameters{
		std::string name;
		std::string author;
		std::string description;
	};
}

#endif //STRATEGYGAME_MODULE_H
