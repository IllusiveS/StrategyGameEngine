//
// Created by wysockipatryk on 2/25/17.
//

#include "Module.h"

namespace BaseModel{
	const std::string &Module::getAuthor() const {
		return author;
	}

	void Module::setAuthor(const std::string &author) {
		Module::author = author;
	}

	const std::string &Module::getDescription() const {
		return description;
	}

	void Module::setDescription(const std::string &description) {
		Module::description = description;
	}

	json Module::serializeToJson() {
		json j = BasicElement::serializeToJson();
		j["description"] = description;
		j["author"] = author;
		j["name"] = templateName;
		return j;
	}

	Module::Module() {
		templateType = "MODULE";
	}
}

