//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <MailCore/MCTaskHandler.h>

@class MFEWSAccount;

@interface MFEWSPersistenceTaskHandler : MCTaskHandler
{
    MFEWSAccount *_account;
}

@property(readonly) __weak MFEWSAccount *account; // @synthesize account=_account;
- (void).cxx_destruct;
- (id)init;
- (id)initWithAccount:(id)arg1;

@end

