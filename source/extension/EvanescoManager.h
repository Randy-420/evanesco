#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface EvanescoManager : NSObject

+(instancetype)sharedInstance;

@property (retain) NSMutableArray *disabledOverrideReasons;

-(BOOL)shouldDisplay;

-(void)recieveNotification:(NSNotification *)notification;
@end