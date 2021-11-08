#import "CPEvanescoPrefs.h"
#import <Preferences/PSTableCell.h>

@interface PSTableCell  (Private)
@property (nonatomic,retain) PSSpecifier * specifier;
@end

#define stepperSpaceFromSides 16
#define stepperSpaceFromSides2 8

@interface CPEvanescoStepperCell : PSTableCell {
	UIStepper *stepper;
	UILabel *label;
}

@property (nonatomic, retain) UIStepper *stepper;
@property (nonatomic, retain) UILabel *label;

- (void)stepperPressed:(id)sender;

@end
