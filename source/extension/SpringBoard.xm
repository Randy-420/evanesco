//
//  SpringBoard.xm
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/15/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import "interfaces.h"
#import "JCPEvanescoController.h"

%hook SpringBoard

%property (strong, nonatomic) JCPEvanescoController *evanescoController;

-(void)applicationDidFinishLaunching:(id)arg1 {
	// Run the original implementation
	%orig;

	// Start up evanesco controller to start managing things
	[self setupEvanesco];
}

-(void)frontDisplayDidChange:(id)arg1 {
	%orig;

	// If an app is opened, we don't need to cast the spell
	if([arg1 isKindOfClass:[objc_getClass("SBApplication") class]] || 
		[arg1 isKindOfClass:[objc_getClass("SBLockScreenViewController") class]] || 
		[arg1 isKindOfClass:[objc_getClass("SBDashBoardViewController") class]]) {

		[self.evanescoController disableActivation];
		
	} else if(arg1 == NULL) {
		[self.evanescoController enableActivation];
	}
}

%new
-(void)setupEvanesco {
	self.evanescoController = [[JCPEvanescoController alloc] init];
}
%end