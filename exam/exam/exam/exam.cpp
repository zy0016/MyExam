// exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkstructor.h"
#include "sortstructor.h"
#include "classstructor.h"
#include "other.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"
#include "mystring.h"
#include "template1.h"
#include "mytree.h"
int _tmain(int argc, _TCHAR* argv[])
{
    LinkAction();
    SortAction();
    ClassAction();
    OtherAction();
    Class2Action();
    TemplateAction();
    Class3Action();
	Class4Action();
    Class5Action();
	testmystring();
	testmytree();
	return 0;
}

