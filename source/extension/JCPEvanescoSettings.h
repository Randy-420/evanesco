//
//  JCPEvanescoSettings.h
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/15/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

@interface JCPEvanescoSettings: NSObject

-(BOOL)enabled;

-(BOOL)hideStatusBar;

-(BOOL)hideDock;

-(CGFloat)fadeAmount;

-(int)timeDelay;

@end