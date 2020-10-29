//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "MessageList-Protocol.h"

@class ManagedList, NSArray, NSString;
@protocol MessageListDelegate;

@interface SingletonMessageList : NSObject <MessageList>
{
    id <MessageListDelegate> _delegate;
    ManagedList *_listOfMessages;
}

@property(readonly, nonatomic) ManagedList *listOfMessages; // @synthesize listOfMessages=_listOfMessages;
@property(readonly, nonatomic) __weak id <MessageListDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
@property(readonly, nonatomic) unsigned long long totalMessageCount;
@property(readonly, copy, nonatomic) NSArray *unrolledObjects;
- (unsigned long long)adjustedIndexOfMessage:(id)arg1 adjustForChildren:(BOOL)arg2;
- (void)removeMessages:(id)arg1 andReplaceMessages:(id)arg2 animate:(BOOL)arg3;
- (void)addPrimaryMessages:(id)arg1 secondaryMessages:(id)arg2;
- (void)updateMessages:(id)arg1;
- (void)applyFilter;
- (void)invert;
- (void)resort;
- (id)init;
- (id)initWithDelegate:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
