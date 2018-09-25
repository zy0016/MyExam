// exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkstructor.h"
#include "sortstructor.h"
#include "classstructor.h"
#include "other.h"
#include "other2.h"
#include "other3.h"
#include "other4.h"
#include "other5.h"
#include "other6.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include "class5.h"
#include "mystring.h"
#include "template1.h"
#include "template2.h"
#include "template3.h"
#include "template4.h"
#include "template5.h"
#include "template6.h"
#include "mytree.h"
int _tmain(int argc, _TCHAR* argv[])
{
    LinkAction();
    SortAction();
    ClassAction();
    OtherAction();
    Class2Action();
    Class3Action();
	Class4Action();
    Class5Action();
	testmystring();
	//testmytree();
	TemplateAction();
	Template2Action();
	Template3Action();
	Template4Action();
	Template5Action();
	Template6Action();
	Other2Action();
	Other3Action();
	Other4Action();
	Other5Action();
    Other6Action();
	return 0;
}

