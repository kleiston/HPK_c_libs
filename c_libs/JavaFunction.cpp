/*
 * JavaFunction.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Kai
 */
#include "JavaFunction.h"


JavaFunction::JavaFunction(JNIEnv *env,jobject instance):Function(){

	this->env = env;
	this-> instance = instance;
	array = env-> NewDoubleArray(1);
	jclass clazz = env->GetObjectClass(instance);
	fct = env->GetMethodID(clazz, "eval", "([D)D");
	//jname = "kaiTest";

}

JavaFunction::~JavaFunction(){};
