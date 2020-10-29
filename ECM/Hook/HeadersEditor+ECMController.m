//
//  HeadersEditor+ECMController.m
//  MailReceipt
//
//  Created by Gyorvari Gabor on 2016. 09. 16..
//  Copyright © 2016. Gyorvari Gabor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import "HeadersEditor+ECMController.h"
#import "HeadersEditor.h"
#import "ComposeBackEnd.h"
#import "ECMController.h"
#import "ComposeViewController.h"
#import "NSObject+LPDynamicIvars.h"

@implementation HeadersEditor_ECMController

- (void)readReceiptClicked:(id)sender {
    NSSegmentedControl *readButton = [self getIvar:@"_readButton"];
    
    HeadersEditor *editor = (HeadersEditor *)self;
    ComposeViewController *composeViewController = editor.composeViewController;
    ComposeBackEnd *backEnd = composeViewController.backEnd;
    [editor.subjectField setStringValue:@"hhhhhhhoooooooo"];
    
    if ([[backEnd getIvar:@"readReceipt"] boolValue]) {
        [readButton setSelected:FALSE forSegment:0];
        [backEnd setIvar:@"readReceipt" value:@NO];
    } else {
        [readButton setSelected:TRUE forSegment:0];
        [backEnd setIvar:@"readReceipt" value:@YES];
    }
}

- (void)deliveryReceiptClicked:(id)sender {
    NSSegmentedControl *deliveryButton = [self getIvar:@"_deliveryButton"];
    
    HeadersEditor *editor = (HeadersEditor *)self;
    ComposeViewController *composeViewController = editor.composeViewController;
    ComposeBackEnd *backEnd = composeViewController.backEnd;
    
    if ([[backEnd getIvar:@"deliveryReceipt"] boolValue]) {
        [deliveryButton setSelected:FALSE forSegment:0];
        [backEnd setIvar:@"deliveryReceipt" value:@NO];
    } else {
        [deliveryButton setSelected:TRUE forSegment:0];
        [backEnd setIvar:@"deliveryReceipt" value:@YES];
    }
}

- (void)MPPAwakeFromNib {
    
    [self MPPAwakeFromNib];
    
    [NSTimer scheduledTimerWithTimeInterval:0.2
    target:self
    selector:@selector(setHeaderInfo)
    userInfo:nil
    repeats:NO];
}
- (void)setHeaderInfo {
    HeadersEditor *editor = (HeadersEditor *)self;
//        [ECMController showAlert:editor.toTitle.stringValue];
    //    ComposeViewController *composeViewController = editor.composeViewController;
    //    ComposeBackEnd *backEnd = composeViewController.backEnd;
//        [editor.subjectTitle setStringValue:@"Sub_Title"];
        [editor.subjectField setStringValue:@"hhhhhhhoooooooo"];
}
@end
