//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "MUITokenAddressDelegate-Protocol.h"

@class NSString;

@interface MailAddressDelegate : NSObject <MUITokenAddressDelegate>
{
}

- (void)_searchForToken:(id)arg1;
- (void)_unblockAddress:(id)arg1;
- (void)_blockAddress:(id)arg1;
- (void)_removeFromVIPs:(id)arg1;
- (void)_addToVIPs:(id)arg1;
- (void)_openNewMessageForTokenAddress:(id)arg1;
- (BOOL)tokenAddressIsBlocked:(id)arg1;
- (BOOL)tokenAddressIsVIP:(id)arg1;
- (void)tokenAddress:(id)arg1 didSelectAction:(long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

