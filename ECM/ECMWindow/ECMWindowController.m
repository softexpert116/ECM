//
//  ECMWindowController.m
//  ECM
//
//  Created by ujs on 10/26/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import "ECMWindowController.h"
#import "ECMController.h"
#import "TimeSettingModalWindow.h"
#import "Constants.h"

@interface ECMWindowController ()

@end

@implementation ECMWindowController
NSString* formatStr,* formatTitle = @"";
NSDate *time11, *time12, *time21, *time22, *time31, *time32;
//NSString *t_text1 = @"", *t_text2 = @"", *t_text3 = @"";

- (void)windowDidLoad {
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    if ([ECMController.userDefaults boolForKey:auto_greet] == YES) {
        [btn_autoGreet setState:NSControlStateValueOn];
    } else {
        [btn_autoGreet setState:NSControlStateValueOff];
    }
    [btn_custom setState:NSControlStateValueOff];
    [btn_random setState:NSControlStateValueOff];
    [btn_time setState:NSControlStateValueOff];

    if ([ECMController.userDefaults objectForKey:format_type] != nil) {
        NSString *formatType = [ECMController.userDefaults objectForKey:format_type];
        if ([formatType  isEqual: @"Custom"]) {
            [btn_custom setState:NSControlStateValueOn];
            
        } else if ([formatType  isEqual: @"Random"]) {
            [btn_random setState:NSControlStateValueOn];
            
        } else if ([formatType  isEqual: @"Time"]) {
            [btn_time setState:NSControlStateValueOn];
            
        }
    }
    if ([ECMController.userDefaults objectForKey:custom_text] != nil) {
        [text_custom setStringValue:[ECMController.userDefaults objectForKey:custom_text]];
    }
    if ([ECMController.userDefaults objectForKey:random_text] != nil) {
        [text_random setStringValue:[ECMController.userDefaults objectForKey:random_text]];
    }
    [self timeSetting];
}
- (void)timeSetting {
    NSString* time = @"";
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"HH:mm"];

    if ([ECMController.userDefaults objectForKey:time_val11] != nil) {
        NSDate* date = [ECMController.userDefaults objectForKey:time_val11];
        time11 = date;
        time = [formatter stringFromDate:date];
    }
    if ([ECMController.userDefaults objectForKey:time_val12] != nil) {
        time = [time stringByAppendingString:@" to "];
        NSDate* date = [ECMController.userDefaults objectForKey:time_val12];
        time12 = date;
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
    }
    if ([ECMController.userDefaults objectForKey:time_text1] != nil) {
        time = [time stringByAppendingString:@" "];
        time = [time stringByAppendingString:[ECMController.userDefaults objectForKey:time_text1]];
    }

    if ([ECMController.userDefaults objectForKey:time_val21] != nil) {
        time = [time stringByAppendingString:@"\n"];
        NSDate* date = [ECMController.userDefaults objectForKey:time_val21];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time21 = date;
    }
    if ([ECMController.userDefaults objectForKey:time_val22] != nil) {
        time = [time stringByAppendingString:@" to "];
        NSDate* date = [ECMController.userDefaults objectForKey:time_val22];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time22 = date;
    }
    if ([ECMController.userDefaults objectForKey:time_text2] != nil) {
        time = [time stringByAppendingString:@" "];
        time = [time stringByAppendingString:[ECMController.userDefaults objectForKey:time_text2]];
    }

    if ([ECMController.userDefaults objectForKey:time_val31] != nil) {
        time = [time stringByAppendingString:@"\n"];
        NSDate* date = [ECMController.userDefaults objectForKey:time_val31];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time31 = date;
    }
    if ([ECMController.userDefaults objectForKey:time_val32] != nil) {
        time = [time stringByAppendingString:@" to "];
        NSDate* date = [ECMController.userDefaults objectForKey:time_val32];
        time = [time stringByAppendingString:[formatter stringFromDate:date]];
        time32 = date;
    }
    if ([ECMController.userDefaults objectForKey:time_text3] != nil) {
        time = [time stringByAppendingString:@" "];
        time = [time stringByAppendingString:[ECMController.userDefaults objectForKey:time_text3]];
    }
    
    [text_time setStringValue:time];
    [self refreshPreview];
}
-(void)refreshPreview {
    if (btn_autoGreet.state == NSControlStateValueOn) {
        NSString* preview = @"";
        if (formatTitle.length > 0) {
            
            if ([formatTitle  isEqual: @"Custom"]) {
                preview = text_custom.stringValue;
            } else if ([formatTitle  isEqual: @"Random"]) {
                if (text_random.stringValue.length > 0) {
                    NSArray *stringArray = [text_random.stringValue componentsSeparatedByString: @","];
                    preview = [ECMController selectRandomStringFromArray:stringArray];
                }
            } else if ([formatTitle  isEqual: @"Time"]) {
                if (time11 != nil) {
                    NSDateFormatter *formatter_H = [[NSDateFormatter alloc] init];
                    [formatter_H setDateFormat:@"HH"];
                    NSDateFormatter *formatter_m = [[NSDateFormatter alloc] init];
                    [formatter_m setDateFormat:@"mm"];
                    NSDate* curDate = [NSDate date];
                    NSString *string_H = [formatter_H stringFromDate:curDate];
                    NSString *string_m = [formatter_m stringFromDate:curDate];
                    
                    if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time11] Minute2:[formatter_H stringFromDate:time11]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time12] Minute2:[formatter_H stringFromDate:time12]]) {
                        preview = [ECMController.userDefaults objectForKey:time_text1];
                    } else if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time21] Minute2:[formatter_H stringFromDate:time21]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time22] Minute2:[formatter_H stringFromDate:time22]]) {
                        preview = [ECMController.userDefaults objectForKey:time_text2];
                    } else if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time31] Minute2:[formatter_H stringFromDate:time31]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time32] Minute2:[formatter_H stringFromDate:time32]]) {
                        preview = [ECMController.userDefaults objectForKey:time_text3];
                    }
                }
                
            }
        }
        [text_preview setStringValue:preview];
    } else {
        [text_preview setStringValue:@""];
    }
}
- (IBAction)clickApply:(id)sender {
    if (btn_autoGreet.state == NSControlStateValueOn) {
        [ECMController.userDefaults setBool:YES forKey:auto_greet];
    } else {
        [ECMController.userDefaults setBool:NO forKey:auto_greet];
    }

    if (formatTitle.length > 0) {
        [ECMController.userDefaults setValue:formatTitle forKey:format_type];
        if ([formatTitle  isEqual: @"Custom"]) {
            [ECMController.userDefaults setValue:text_custom.stringValue forKey:custom_text];
        } else if ([formatTitle  isEqual: @"Random"]) {
            [ECMController.userDefaults setValue:text_random.stringValue forKey:random_text];
        } else if ([formatTitle  isEqual: @"Time"]) {

        }
    }
    [ECMController showAlertWithTitle:@"Success" Message:@"Successfully applied!"];

}
- (IBAction)clickAutoGreet:(id)sender {
    [self refreshPreview];
}
- (IBAction)clickClose:(id)sender {
    [[self window] close];
}
- (IBAction)selectFormat:(NSButton *)sender {
    formatTitle = [sender title];
    [self refreshPreview];
}
- (IBAction)openTimeSetting:(NSButton *)sender {
    TimeSettingModalWindow* windowController = [[TimeSettingModalWindow alloc] initWithWindowNibName:@"TimeSettingModalWindow"];
    [NSApp runModalForWindow:[windowController window]];
    [self timeSetting];
}
- (void)windowWillClose:(NSNotification *)notification
{
    [NSApp stopModal];
}

@end
