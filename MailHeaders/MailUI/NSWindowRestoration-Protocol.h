//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class NSCoder, NSString;

@protocol NSWindowRestoration <NSObject>
+ (void)restoreWindowWithIdentifier:(NSString *)arg1 state:(NSCoder *)arg2 completionHandler:(void (^)(NSWindow *, NSError *))arg3;
@end
