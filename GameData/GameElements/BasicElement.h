//
// Created by wysockipatryk on 2/25/17.
//

#ifndef STRATEGYGAME_BASICELEMENT_H
#define STRATEGYGAME_BASICELEMENT_H

#include <string>
#include "json/json.hpp"

using json = nlohmann::json;

namespace BaseModel {
	class BasicElement {
	protected:
		std::string templateName;
		std::string templateType;

		BasicElement();

		BasicElement(json j);

	public:
		const std::string &getTemplateName() const;

		void setTemplateName(const std::string &templateName);

		const std::string &getTemplateType() const;

		void setTemplateType(const std::string &templateType);

		virtual json serializeToJson();
	};
}

#endif //STRATEGYGAME_BASICELEMENT_H
