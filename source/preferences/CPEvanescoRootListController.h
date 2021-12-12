//
//  CPEvanescoRootListController.h
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/16/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import <Preferences/PSListController.h>

@interface PSListController (iOS12Plus)
-(BOOL)containsSpecifier:(PSSpecifier *)arg1;
@end

@interface CPEvanescoRootListController : PSListController

@property (nonatomic, strong) NSArray *chosenIDs;
@property (nonatomic, retain) NSMutableDictionary *savedSpecifiers;

@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSString *footNote;

@property (nonatomic, assign) BOOL evanesco;
@property (nonatomic, assign) BOOL DSInstalled;
@property (nonatomic, assign) BOOL hideDS;
@property (nonatomic, assign) BOOL split;

-(void)update;
-(void)showMe:(NSString *)showMe after:(NSString*)after animate:(bool)animate;
-(void)hideMe:(NSString *)hideMe animate:(bool)animate;
@end

static BOOL getBool(NSString *pkey, BOOL defaultValue) {
	NSDictionary *Dict = [NSDictionary dictionaryWithContentsOfFile:@"/var/mobile/Library/Preferences/com.cpdigitaldarkroom.itsevanesco.plist"];

	return [Dict objectForKey:pkey] ? [[Dict objectForKey:pkey] boolValue] : defaultValue;
}