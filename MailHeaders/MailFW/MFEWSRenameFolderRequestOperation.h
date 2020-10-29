//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Mail/MFEWSRequestOperation.h>

@class MFEWSGetFolderResponseOperation, NSString;

@interface MFEWSRenameFolderRequestOperation : MFEWSRequestOperation
{
    NSString *_folderIdString;
    NSString *_folderName;
    MFEWSGetFolderResponseOperation *_changeKeysResponse;
}

@property(readonly, nonatomic) MFEWSGetFolderResponseOperation *changeKeysResponse; // @synthesize changeKeysResponse=_changeKeysResponse;
@property(readonly, copy, nonatomic) NSString *folderName; // @synthesize folderName=_folderName;
@property(readonly, copy, nonatomic) NSString *folderIdString; // @synthesize folderIdString=_folderIdString;
- (void).cxx_destruct;
- (id)prepareRequest;
- (BOOL)isFolderRequest;
- (id)activityString;
- (id)initWithGateway:(id)arg1 errorHandler:(id)arg2;
- (id)initWithEWSFolderIdString:(id)arg1 name:(id)arg2 gateway:(id)arg3;

@end

