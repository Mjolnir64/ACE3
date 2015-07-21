class RscButtonMenu;
class RscControlsGroupNoScrollbars;
class RscFrame;
class RscMapControl;
class RscPicture;
class RscStructuredText;
class RscText;
class RscTree;

class GVAR(interface) {
    idd = 12249;
    enableSimulation = 1;
    movingEnable = 0;
    onLoad = QUOTE([ARR_2('onLoad',_this)] call FUNC(handleInterface));
    onUnload = QUOTE([ARR_2('onUnload',_this)] call FUNC(handleInterface));
    onKeyDown = QUOTE([ARR_2('onKeyDown',_this)] call FUNC(handleInterface));
    onKeyUp = QUOTE([ARR_2('onKeyUp',_this)] call FUNC(handleInterface));
    class controlsBackground {
        class mouseHandler: RscControlsGroupNoScrollbars {
            x = safeZoneXAbs;
            y = safeZoneY;
            w = safeZoneWAbs;
            h = safeZoneH;
            onMouseButtonDown = QUOTE([ARR_2('onMouseButtonDown',_this)] call FUNC(handleInterface));
            onMouseButtonUp = QUOTE([ARR_2('onMouseButtonUp',_this)] call FUNC(handleInterface));
            onMouseZChanged = QUOTE([ARR_2('onMouseZChanged',_this)] call FUNC(handleInterface));
            onMouseMoving = QUOTE([ARR_2('onMouseMoving',_this)] call FUNC(handleInterface));
        };
    };
    class controls {
        class compass: RscControlsGroupNoScrollbars {
            idc = IDC_COMP;
            x = COMPASS_X;
            y = safeZoneY;
            w = COMPASS_W;
            h = TOOL_H;
            class controls {
                class compassBack: RscText {
                    x = 0;
                    y = 0;
                    w = COMPASS_W;
                    h = TOOL_H;
                    colorBackground[] = {COL_BACK};
                };
                class compass0_90: RscPicture {
                    idc = IDC_COMP_0;
                    x = COMPASS_W * 0.5;
                    y = 0;
                    w = COMPASS_W * 0.5;
                    h = TOOL_H;
                    text = "A3\UI_F_Curator\Data\CfgIngameUI\compass\texture180_ca.paa";
                };
                class compass90_180: compass0_90 {
                    idc = IDC_COMP_90;
                    x = COMPASS_W;
                    text = "A3\UI_F_Curator\Data\CfgIngameUI\compass\texture270_ca.paa";
                };
                class compass180_270: compass0_90 {
                    idc = IDC_COMP_180;
                    x = 0;
                    text = "A3\UI_F_Curator\Data\CfgIngameUI\compass\texture0_ca.paa";
                };
                class compass270_0: compass0_90 {
                    idc = IDC_COMP_270;
                    x = COMPASS_W * -0.5;
                    text = "A3\UI_F_Curator\Data\CfgIngameUI\compass\texture90_ca.paa";
                };
                class compassCaret: RscFrame {
                    x = COMPASS_W * 0.5;
                    y = 0;
                    w = 0;
                    h = TOOL_H;
                    colorText[] = {COL_FORE};
                };
                class compassFrame: compassBack {
                    style = 64;
                    shadow=2;
                    colorText[] = {COL_FORE};
                };
            };
        };
        class toolbar: RscControlsGroupNoScrollbars {
            idc = IDC_TOOL;
            x = safeZoneX;
            y = safeZoneY + safeZoneH - TOOL_H;
            w = safeZoneW;
            h = TOOL_H;
            class controls {
                class nameTool: RscText {
                    idc = IDC_TOOL_NAME;
                    style = 2;
                    x = 0;
                    y = 0;
                    w = TOOL_W * 2;
                    h = TOOL_H;
                    shadow = 2;
                    colorText[]={COL_FORE};
                    colorBackground[] = {COL_BACK};
                    sizeEx = H_PART(1);
                };
                class nameFrame: nameTool {
                    idc = -1;
                    style = 64;
                };
                class viewTool: nameTool {
                    idc = IDC_TOOL_VIEW;
                    x = TOOL_W * 2 + MARGIN;
                    w = TOOL_W;
                };
                class viewFrame: viewTool {
                    idc = -1;
                    style = 64;
                };
                class fovTool: viewTool {
                    idc = IDC_TOOL_FOV;
                    x = TOOL_W * 3 + MARGIN * 2;
                };
                class fovFrame: fovTool {
                    idc = -1;
                    style = 64;
                };
                class clockTool: viewTool {
                    idc = IDC_TOOL_CLOCK;
                    x = safeZoneW - TOOL_W * 3 - MARGIN * 2;
                };
                class clockFrame: clockTool {
                    idc = -1;
                    style = 64;
                };
                class visionTool: viewTool {
                    idc = IDC_TOOL_VISION;
                    x = safeZoneW - TOOL_W * 2 - MARGIN;
                };
                class visionFrame: visionTool {
                    idc = -1;
                    style = 64;
                };
                class speedTool: viewTool {
                    idc = IDC_TOOL_SPEED;
                    x = safeZoneW - TOOL_W;
                };
                class speedFrame: speedTool {
                    idc = -1;
                    style = 64;
                };
            };
        };
        class unitTree: RscTree {
            idc = IDC_UNIT;
            x = safeZoneX;
            y = safeZoneY + TOOL_H * 2;
            w = TOOL_W * 2;
            h = safeZoneH - TOOL_H * 4;
            sizeEx = H_PART(0.8);
            borderSize = 1;
            colorBorder[] = {COL_FORE};
            colorBackground[] = {COL_BACK};
            colorSelect[] = {
                "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
                "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
                1
            };
            multiselectEnabled = 0;
            onTreeDblClick = QUOTE([ARR_2('onTreeDblClick',_this)] call FUNC(handleInterface));
        };
        class mapOverlay: RscMapControl {
            idc = IDC_MAP;
            x = safeZoneX;
            y = safeZoneY;
            w = safeZoneW;
            h = safeZoneH;
            onMouseButtonDblClick = QUOTE([ARR_2('onMapDblClick',_this)] call FUNC(handleInterface));
        };
        class helpSplash: RscControlsGroupNoScrollbars {
            idc = IDC_HELP;
            x = 0.5 - W_PART(12);
            y = 0.5 - H_PART(12);
            w = W_PART(24);
            h = H_PART(24);
            class controls {
                class helpBack: RscText {
                    x = 0;
                    y = 0;
                    w = W_PART(24);
                    h = H_PART(24);
                    colorBackground[] = {COL_BACK};
                };
                class helpTitle: helpBack {
                    h = H_PART(1);
                    colorText[]={COL_FORE};
                    colorBackground[] = {COL_FORE_D};
                    sizeEx = H_PART(1);
                    text = CSTRING(HelpTitle);
                };
            };
        };
    };
};
