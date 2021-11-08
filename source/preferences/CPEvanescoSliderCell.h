#import <Preferences/PSSliderTableCell.h>

@interface CPEvanescoSliderCell : PSSliderTableCell <UIAlertViewDelegate, UITextFieldDelegate> {
    CGFloat minimumValue;
    CGFloat maximumValue;
    
    NSString *_label;
    NSString *_footerLabel;
    
    UIAlertView * alert;
}
- (void)presentPopup;
- (void) typeMinus;
- (void) typePoint;

@property (nonatomic,strong) UILabel *labelText;
@property (nonatomic,strong) UILabel *footerText;

@end
