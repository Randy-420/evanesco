//
//  SBFloatingDockRootViewController.xm
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/16/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import "interfaces.h"
#import "JCPEvanescoController.h"

%hook SBFloatingDockRootViewController
- (void)setPresentationProgress:(double)arg1 animated:(BOOL)arg2 interactive:(BOOL)arg3 withCompletion:(id)arg4 {
	if (![((SpringBoard *)[UIApplication sharedApplication]).evanescoController shouldPreventDockFloatUp]) {
		%orig;
	}
}
%end