//
//  ECMWindowController.h
//  ECM
//
//  Created by ujs on 10/26/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ECMWindowController : NSWindowController {
    __weak IBOutlet NSButton *btn_autoGreet;
    __weak IBOutlet NSTextField *text_custom;
    __weak IBOutlet NSTextField *text_random;
    __weak IBOutlet NSButton *btn_custom;
    __weak IBOutlet NSButton *btn_random;
    __weak IBOutlet NSButton *btn_time;
    __weak IBOutlet NSTextField *text_time;
    __weak IBOutlet NSTextField *text_preview;
}

@end

NS_ASSUME_NONNULL_END
