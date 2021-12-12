//
//  SPEvanescoPrefs.h
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/16/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#import <MessageUI/MessageUI.h>
#import <MobileGestalt/MobileGestalt.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSSpecifier.h>
#import <Social/Social.h>
#import <Twitter/TWTweetComposeViewController.h>
#import <UIKit/UIImage+Private.h>
#import <version.h>

#define kIsDemo  NO

#define buttonCellWithName(name) [PSSpecifier preferenceSpecifierNamed:name target:self set:NULL get:NULL detail:NULL cell:PSButtonCell edit:Nil]
#define groupSpecifier(name) [PSSpecifier groupSpecifierWithName:name]
#define sliderCellWithName(name) [PSSpecifier preferenceSpecifierNamed: name target:self set:@selector(setPreferenceValue:specifier:) get:@selector(readPreferenceValue:) detail:NULL cell:PSSliderCell edit:Nil]
#define subtitleSwitchCellWithName(name) [PSSpecifier preferenceSpecifierNamed:name target:self set:@selector(setPreferenceValue:specifier:) get:@selector(readPreferenceValue:) detail:NULL cell:PSSwitchCell edit:Nil]
#define switchCellWithName(name) [PSSpecifier preferenceSpecifierNamed:name target:self set:@selector(setPreferenceValue:specifier:) get:@selector(readPreferenceValue:) detail:NULL cell:PSSwitchCell edit:Nil]
#define textCellWithName(name) [PSSpecifier preferenceSpecifierNamed:name target:self set:NULL get:NULL detail:NULL cell:PSStaticTextCell edit:Nil]

#define setId(id) [specifier setProperty:id forKey:@"id"]
#define setClassForSpec(className) [specifier setProperty:className forKey:@"cellClass"]
#define setDefaultForSpec(sDefault) [specifier setProperty:sDefault forKey:@"default"]
#define setKeyForSpec(key) [specifier setProperty:key forKey:@"key"]
#define setFooterForSpec(footer) [specifier setProperty:footer forKey:@"footerText"]
#define setMinForSpec(minimum) [specifier setProperty:minimum forKey:@"min"]
#define setMaxForSpec(maximum) [specifier setProperty:maximum forKey:@"max"]
#define setShowsValue(shows) [specifier setProperty:shows forKey:@"showValue"]