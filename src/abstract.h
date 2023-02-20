/*
 * abstract.h
 *
 *  Created on: 16 oct. 2022
 *      Author: pascal
 */

#ifndef ABSTRACT_H_
#define ABSTRACT_H_

#include <iostream>

class IParent;
class Derived;
class OtherDerived;

class IButton {
private:
	std::string label;
public:
	virtual ~IButton() {
	}

	virtual void action(const IParent &p) const = 0;
	virtual void action(const Derived &d) const = 0;
	virtual void action(const OtherDerived &o) const = 0;

	const std::string& getLabel() const;
	void setLabel(const std::string &label);
};

class ButtonStop: public IButton {
public:
	ButtonStop();

	void action(const IParent &p) const override;
	void action(const Derived &d) const override;
	void action(const OtherDerived &o) const override;
};

class ButtonStart: public IButton {
public:
	ButtonStart();

	void action(const IParent &p) const override;
	void action(const Derived &d) const override;
	void action(const OtherDerived &o) const override;
};

class IParent {
private:
	std::string name;
public:
	IButton *buttonStop = NULL;
	IButton *buttonStart = NULL;

	virtual ~IParent() {
		delete buttonStop;
		delete buttonStart;
	}

	virtual void display() const = 0;

	const std::string& getName() const ;
	void setName(const std::string &name);

	void callInParentClass(const IButton &) const;
};

class Derived: public IParent {
private:
public:
	Derived(const char *label);

	void display() const override;
	void callInDerivedClass(const IButton &) const;
};

class OtherDerived: public IParent {
private:
	char buffer[100000];
	std::string dummy;
public:
	OtherDerived(const char *label);

	void display() const override;
	void callInDerivedClass(const IButton &) const;
};

#endif /* ABSTRACT_H_ */
