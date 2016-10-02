#include "stdafx.h"
#include "WinToastTemplate.h"
#include "WinToastHandlerExample.h"

WinToastTemplate::WinToastTemplate(const WinToastTemplateType& type) :
_type(type)
{
	initComponentsFromType();
}


WinToastTemplate::~WinToastTemplate()
{
	_textFields.clear();
}


void WinToastTemplate::setTextField(const wstring& txt, int pos) {
	_textFields[pos] = txt;
}
void WinToastTemplate::setImagePath(const wstring& imgPath) {
	if (!_hasImage)
		return;
	_imagePath = imgPath;
}

void WinToastTemplate::initComponentsFromType() {
	_hasImage = _type < ToastTemplateType_ToastText01;
	_textFieldsCount = (_hasImage ? _type : _type - ToastTemplateType_ToastText01) + 1;
	_textFields = vector<wstring>(_textFieldsCount, L"");
}


WinToastHandler* WinToastTemplate::handler() const {
	ComPtr<WinToastHandlerExample> handler(new WinToastHandlerExample);
	return handler.Get();
}