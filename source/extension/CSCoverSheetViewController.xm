//
//  CSCoverSheetViewController.xm
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/16/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import "interfaces.h"
#import "JCPEvanescoController.h"

%hook CSCoverSheetViewController

-(void)finishUIUnlockFromSource:(int)arg1 {
	%orig;
	[((SpringBoard *)[UIApplication sharedApplication]).evanescoController enableActivation];
}

- (void)setInScreenOffMode:(BOOL)screenOff forAutoUnlock:(BOOL)arg2 fromUnlockSource:(int)arg3{
	%orig;

	if (screenOff)
		[((SpringBoard *)[UIApplication sharedApplication]).evanescoController tearDown];
}
%end