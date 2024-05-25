//
//  SBUIController.xm
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/16/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import "interfaces.h"
#import "JCPEvanescoController.h"

%hook SBUIController

-(BOOL)handleHomeButtonSinglePressUp {
	[((SpringBoard *)[UIApplication sharedApplication]).evanescoController noteUserActive];
	return %orig;
}

-(BOOL)handleHomeButtonDoublePressDown {
	[((SpringBoard *)[UIApplication sharedApplication]).evanescoController noteUserActive];
	return %orig;
}

%end