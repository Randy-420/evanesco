//
//  interfaces.h
//  Evanesco!
//
//  Created by Juan Carlos Perez on 01/15/20.
//  Copyright © 2020 CP Digital Darkroom. All rights reserved.
//

#define kPrefDomain "com.cpdigitaldarkroom.itsevanesco"

#define kIsDemo  NO

@interface CSCoverSheetViewController : UIViewController
@end

@interface FBSystemApp : UIApplication
@end

@interface SBAppStatusBarSettingsAssertion : NSObject
-(id)initWithStatusBarHidden:(BOOL)arg1 atLevel:(unsigned long long)arg2 reason:(id)arg3 ; 
@end

@interface SBAppStatusBarAssertionManager : NSObject
+ (id)sharedInstance;
-(void)_addStatusBarSettingsAssertion:(id)arg1 ;
-(void)_removeStatusBarSettingsAssertion:(id)arg1 ;
@end

@interface SBDockView : UIView
-(void)setBackgroundAlpha:(CGFloat)alpha;
@end

@interface SBIconController : NSObject
+ (id)sharedInstance;
-(id)_rootFolderController;
@end


@interface SBIcon : NSObject
-(_Bool)isFolderIcon;
-(id)leafIdentifier;
-(id)getIconImage:(int)arg1;
@end

@interface SBIconView : UIView
@property(nonatomic, retain) SBIcon *icon;
-(UIView *)iconImageView;
-(UIView *)_iconImageView;
-(UIView *)iconBackgroundView;
-(_Bool)isInDock;
-(void)setLabelHidden:(_Bool)arg1;
-(void)_applyIconLabelAlpha:(double)arg1;
@end

@interface SBIconViewMap : NSObject
+ (instancetype)homescreenMap;
-(SBIconView *)mappedIconViewForIcon:(SBIcon *)icon;
@end

@interface SBRootFolderView : NSObject
@property (nonatomic, readonly) SBDockView *dockView;


-(void)setPageControlHidden:(BOOL)hidden;
@end

@interface SBIconListView : UIView
@property (assign,getter=isEditing,nonatomic) BOOL editing;
-(NSArray *)icons;
-(SBIconViewMap *)viewMap;
-(void)layoutIconsNow;
-(CATransform3D)_transformForIconAtIndex:(NSUInteger)index inOrientation:(NSInteger)orientation;
@end

@interface SBNestingViewController: UIViewController
@end

@interface SBFloatingDockController : NSObject
+ (BOOL)isFloatingDockSupported;
-(id)initWithIconController:(id)arg1 ;
-(void)dismissFloatingDockIfPresentedAnimated:(BOOL)arg1 completionHandler:(/*^block*/id)arg2 ;
-(void)presentFloatingDockIfDismissedAnimated:(BOOL)arg1 completionHandler:(/*^block*/id)arg2 ;
@end

@interface SBFolderController : SBNestingViewController
@property (nonatomic,readonly) SBIconListView * currentIconListView; 
@property (nonatomic,readonly) SBIconListView * dockListView;
@property (nonatomic,readonly) SBHomeScreenView * SBHS;

-(void)setPageControlHidden:(BOOL)arg1 ;
@end

@interface SBRootFolderController: SBFolderController
@property (nonatomic, readonly) SBRootFolderView *contentView;

-(id)beginModifyingDockOffscreenFractionForReason:(id)arg1;

@end

@interface SpringBoard : FBSystemApp
@end

@class JCPEvanescoController;

@interface SpringBoard (Evanesco)

@property (strong, nonatomic) JCPEvanescoController *evanescoController;

-(void)setupEvanesco;

@end

@protocol SBFloatingDockRootViewControllerDelegate <NSObject>

@optional
-(void)floatingDockRootViewController:(id)arg1 modifyProgress:(double)arg2 interactive:(BOOL)arg3 completion:(id)arg4;
-(BOOL)floatingDockRootViewControllerShouldHandlePanGestureRecognizer:(id)arg1;
-(void)floatingDockRootViewController:(id)arg1 willPerformTransitionWithFolder:(id)arg2 presenting:(BOOL)arg3 withTransitionCoordinator:(id)arg4;
-(void)floatingDockRootViewControllerDidEndPresentationTransition:(id)arg1;
-(double)minimumHomeScreenScaleForFloatingDockRootViewController:(id)arg1;

@required
-(void)floatingDockRootViewController:(id)arg1 willChangeToHeight:(double)arg2;
-(void)floatingDockRootViewController:(id)arg1 floatingDockWantsToBePresented:(BOOL)arg2;
@end

@interface SBFloatingDockRootViewController : UIViewController
@property (weak, nonatomic) id<SBFloatingDockRootViewControllerDelegate> delegate; 
-(void)setPresentationProgress:(double)arg1 animated:(BOOL)arg2 interactive:(BOOL)arg3 withCompletion:(/*^block*/id)arg4 ;
@end

@interface SBFloatingDockWindow : UIWindow
-(SBFloatingDockRootViewController *)floatingDockRootViewController;
@end

@interface UIApplication (EV)
-(id)statusBar;
-(id)statusBarWindow;
@end

@interface UIStatusBar
-(void)setHidden:(BOOL)arg1;
@end

@interface UIStatusBarWindow : UIWindow
@end