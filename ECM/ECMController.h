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

NS_ASSUME_NONNULL_BEGIN

@interface ECMController : NSObject
@property (strong, nonatomic) ECMWindowController *windowController;
+ (NSUserDefaults *) userDefaults;
+ (void) showAlertWithTitle: (NSString *)title Message: (NSString *)msg;
+ (BOOL)isElCapitan;
+ (NSString *) extractEmailAddress:(NSString *)address;
+ (NSString *) selectRandomStringFromArray:(NSArray *)array;
+ (BOOL) compareHour1:(NSString *)h1 Minute1:(NSString *)m1 Hour2:(NSString*)h2 Minute2:(NSString*)m2;
@end


NS_ASSUME_NONNULL_END
