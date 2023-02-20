//============================================================================
// Name        : abstract.cpp
// Author      : pascal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "abstract.h"

using namespace std;

const std::string& IButton::getLabel() const {
	return label;
}

void IButton::setLabel(const std::string &label) {
	this->label = label;
}

ButtonStop::ButtonStop() {
	setLabel("Stop");
}

void ButtonStop::action(const IParent &p) const {
	p.callInParentClass(*this);
}

void ButtonStop::action(const Derived &d) const {
	d.callInDerivedClass(*this);
}

void ButtonStop::action(const OtherDerived &o) const {
	o.callInDerivedClass(*this);
}

ButtonStart::ButtonStart() {
	setLabel("Start");
}

void ButtonStart::action(const IParent &p) const {
	p.callInParentClass(*this);
}

void ButtonStart::action(const Derived &d) const {
	d.callInDerivedClass(*this);
}

void ButtonStart::action(const OtherDerived &o) const {
	o.callInDerivedClass(*this);
}

const string& IParent::getName() const {
	return name;
}

void IParent::setName(const string &name) {
	this->name = name;
}

void IParent::callInParentClass(const IButton& button) const {
	cout <<getName() <<" call Parent Class from " <<button.getLabel() << endl;
}

Derived::Derived(const char *label) {
	setName(label);
	buttonStop = new ButtonStop();
	buttonStart = new ButtonStart();
}

void Derived::display() const {
	cout << getName() << endl;
	buttonStop->action(*this);
	buttonStop->action((const IParent&) *this);

	buttonStart->action(*this);
	buttonStart->action((const IParent&) *this);
}

void Derived::callInDerivedClass(const IButton& button) const {
	cout <<getName() <<" call Derived Class from " <<button.getLabel() << endl;
}

OtherDerived::OtherDerived(const char *label) {
	setName(label);
	buttonStop = new ButtonStop();
	buttonStart = new ButtonStart();
}

void OtherDerived::display() const {
	cout << getName() << endl;
	buttonStop->action(*this);
	buttonStop->action((const IParent&) *this);

	buttonStart->action(*this);
	buttonStart->action((const IParent&) *this);
}

void OtherDerived::callInDerivedClass(const IButton& button) const {
	cout <<getName() <<" call Other Derived Class from " <<button.getLabel() << endl;
}

int main() {
	IParent *derived = new Derived("Derived");
	derived->display();
	delete derived;

	IParent *other = new OtherDerived("Other");
	other->display();
	delete other;

	return 0;
}
