#include "script_component.hpp"

[QGVAR(handoff), {_this call FUNC(handleHandoff)}] call CBA_fnc_addEventHandler;

["ACE3 Weapons", QGVAR(cycleFireMode), localize LSTRING(CycleFireMode),
{
    [] call FUNC(cycleAttackProfileKeyDown);
    false
},
{
    false
},
[15, [false, true, false]], false] call CBA_fnc_addKeybind;  //Ctrl+Tab Key

#ifdef ENABLE_PROJECTILE_CAMERA
GVAR(dev_fnc_projectileCamera) = compile preprocessFileLineNumbers QPATHTOF(dev\projectileCamera.sqf);
#endif
