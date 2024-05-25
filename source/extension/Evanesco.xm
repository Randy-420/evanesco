#include "EvanescoManager.h"

/////Boxy
%hook WVGestureController
-(void)showPopup{
	%orig;
	[EvanescoManager.sharedInstance.disabledOverrideReasons addObject:@"Boxy"];
}
%end

%hook WVPopupView
-(void)hide{
	%orig;
	[EvanescoManager.sharedInstance.disabledOverrideReasons removeObject:@"Boxy"];
}
%end

/////Springboard Editing
%hook SBFolderController
-(void)setEditing:(BOOL)arg1 animated:(BOOL)arg2 {
	%orig;
	if (arg1) [EvanescoManager.sharedInstance.disabledOverrideReasons addObject:@"SBEditing"];
	else [EvanescoManager.sharedInstance.disabledOverrideReasons removeObject:@"SBEditing"];
}
%end

//////Atria editing
%hook ARIEditManager
- (void)toggleEditView:(BOOL)arg1 withTargetLocation:(NSString *)arg2{
	if (arg1) [EvanescoManager.sharedInstance.disabledOverrideReasons addObject:@"Atria"];
	else [EvanescoManager.sharedInstance.disabledOverrideReasons removeObject:@"Atria"];

	%orig;
}
%end

//////Cuboid editing
%hook CBDView
-(void)setPresented:(BOOL)arg1{
	if (arg1) [EvanescoManager.sharedInstance.disabledOverrideReasons addObject:@"Cuboid"];
	else [EvanescoManager.sharedInstance.disabledOverrideReasons removeObject:@"Cuboid"];
	%orig;
}
%end