//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Mail/MFEWSNetworkTaskOperation.h>

@class MFEWSMailboxItemsBatch;
@protocol MFEWSFetchMessageMetadataOperationDelegate;

@interface MFEWSFetchMessageMetadataOperation : MFEWSNetworkTaskOperation
{
    id <MFEWSFetchMessageMetadataOperationDelegate> _delegate;
    MFEWSMailboxItemsBatch *_batch;
}

+ (id)_propertiesForItemClass:(Class)arg1;
+ (id)_shapeForType:(Class)arg1;
@property(readonly, nonatomic) MFEWSMailboxItemsBatch *batch; // @synthesize batch=_batch;
@property(nonatomic) __weak id <MFEWSFetchMessageMetadataOperationDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)main;
- (id)init;
- (id)initWithBatch:(id)arg1;

@end

