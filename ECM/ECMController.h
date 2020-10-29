//
//  ECMController.h
//  ECM
//
//  Created by ujs on 10/22/20.
//  Copyright © 2020 ujs. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <Cocoa/Cocoa.h>
#import "ECMWindowController.h"

//NS_ASSUME_NONNULL_BEGIN

@interface ECMController : NSObject
@property (strong, nonatomic) ECMWindowController *windowController;
+ (void)showAlert:(NSString *)msg;
+ (BOOL)isElCapitan;
+ (NSString *) extractEmailAddress:(NSString *)address;
@end


//NS_ASSUME_NONNULL_END
