//
// Created by wysockipatryk on 2/25/17.
//

#include "BasicElement.h"

namespace BaseModel{
	const std::string &BasicElement::getTemplateName() const {
		return templateName;
	}

	void BasicElement::setTemplateName(const std::string &templateName) {
		BasicElement::templateName = templateName;
	}

	const std::string &BasicElement::getTemplateType() const {
		return templateType;
	}

	void BasicElement::setTemplateType(const std::string &templateType) {
		BasicElement::templateType = templateType;
	}

	BasicElement::BasicElement() {

	}

	BasicElement::BasicElement(json j) {

	}

	json BasicElement::serializeToJson() {
		json j;
		j["templateName"] = templateName;
		j["templateType"] = templateType;
		j["module"] = module;
		return j;
	}

	const std::string &BasicElement::getModule() const {
		return module;
	}

	void BasicElement::setModule(const std::string &module) {
		BasicElement::module = module;
	}

	const std::string &BasicElement::getLocation() const {
		return location;
	}

	void BasicElement::setLocation(const std::string &location) {
		BasicElement::location = location;
	}
}

