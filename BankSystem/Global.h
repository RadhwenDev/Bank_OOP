#pragma once
#include <iostream>
#include "clsUser.h"
using namespace std;

clsUser CurrentUser = clsUser::Find("", "");

enum enLocked {eLocked = 0, eUnlocked = 1};

enLocked Status = eUnlocked;