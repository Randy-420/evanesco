//
//  JCPEvanescoController.h
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/15/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

@interface SBHomeScreenView : UIView

@end

@interface JCPEvanescoController: NSObject{
	NSString *viewDump;
}
@property (assign, nonatomic) BOOL shouldPreventDockFloatUp;

-(void)disableActivation;

-(void)enableActivation;

// let the controller know some user activity happened
-(void)noteUserActive;

// remove timers and clear actively applied spell
-(void)tearDown;
@end

