//
//  TimeSettingModalWindow.m
//  ECM
//
//  Created by ujs on 10/28/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "TimeSettingModalWindow.h"
#import "Constants.h"
#import "ECMController.h"

@interface TimeSettingModalWindow ()

@end

@implementation TimeSettingModalWindow
- (void)awakeFromNib
{
    [super awakeFromNib];
    [self.window center];
}
- (void)windowDidLoad {
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    [time11 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time12 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time21 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time22 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time31 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    [time32 setDatePickerElements:NSHourMinuteDatePickerElementFlag];
    
    if ([ECMController.userDefaults objectForKey:time_text1] != nil) {
        [text1 setStringValue:[ECMController.userDefaults objectForKey:time_text1]];
    }
    if ([ECMController.userDefaults objectForKey:time_val11] != nil) {
        [time11 setDateValue:[ECMController.userDefaults objectForKey:time_val11]];
    }
    if ([ECMController.userDefaults objectForKey:time_val12] != nil) {
        [time12 setDateValue:[ECMController.userDefaults objectForKey:time_val12]];
    }
    
    if ([ECMController.userDefaults objectForKey:time_text2] != nil) {
        [text2 setStringValue:[ECMController.userDefaults objectForKey:time_text2]];
    }
    if ([ECMController.userDefaults objectForKey:time_val21] != nil) {
        [time21 setDateValue:[ECMController.userDefaults objectForKey:time_val21]];
    }
    if ([ECMController.userDefaults objectForKey:time_val22] != nil) {
        [time22 setDateValue:[ECMController.userDefaults objectForKey:time_val22]];
    }

    if ([ECMController.userDefaults objectForKey:time_text3] != nil) {
        [text3 setStringValue:[ECMController.userDefaults objectForKey:time_text3]];
    }
    if ([ECMController.userDefaults objectForKey:time_val31] != nil) {
        [time31 setDateValue:[ECMController.userDefaults objectForKey:time_val31]];
    }
    if ([ECMController.userDefaults objectForKey:time_val32] != nil) {
        [time32 setDateValue:[ECMController.userDefaults objectForKey:time_val32]];
    }
}
- (IBAction)clickApply:(id)sender {
//    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
//    [formatter setDateFormat:@"yyyy MM dd HH:mm"];
//    NSString *stringFromDate = [formatter stringFromDate:[time11 dateValue]];
//    [ECMController showAlertWithTitle:@"" Message:stringFromDate];
    
    [ECMController.userDefaults setValue:text1.stringValue forKey:time_text1];
    [ECMController.userDefaults setValue:[time11 dateValue] forKey:time_val11];
    [ECMController.userDefaults setValue:[time12 dateValue] forKey:time_val12];
    
    [ECMController.userDefaults setValue:text2.stringValue forKey:time_text2];
    [ECMController.userDefaults setValue:[time21 dateValue] forKey:time_val21];
    [ECMController.userDefaults setValue:[time22 dateValue] forKey:time_val22];

    [ECMController.userDefaults setValue:text3.stringValue forKey:time_text3];
    [ECMController.userDefaults setValue:[time31 dateValue] forKey:time_val31];
    [ECMController.userDefaults setValue:[time32 dateValue] forKey:time_val32];
//    [[self window] close];
    [ECMController showAlertWithTitle:@"Success" Message:@"Successfully applied!"];
    [self clickCancel:nil];

}
- (IBAction)clickCancel:(id)sender {
    [[self window] close];
}


- (void)windowWillClose:(NSNotification *)notification
{
    [NSApp stopModal];
}
@end
