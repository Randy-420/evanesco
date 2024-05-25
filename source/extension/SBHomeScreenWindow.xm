//
//  SBHomeScreenWindow.xm
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/16/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import "interfaces.h"
#import "JCPEvanescoController.h"

%hook SBHomeScreenWindow

-(void)sendEvent:(UIEvent *)event {
	%orig;

	NSSet *allTouches = [event allTouches];
	if ([allTouches count] > 0) {
		UITouchPhase phase = ((UITouch *)[allTouches anyObject]).phase;
		if (phase == UITouchPhaseBegan /*|| phase == UITouchPhaseEnded*/)
			[((SpringBoard *)[UIApplication sharedApplication]).evanescoController noteUserActive];
	}
}

%end