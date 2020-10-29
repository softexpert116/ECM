//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <MailCore/MCFileWrapper.h>

@class NSURL;

@interface MCLargeAttachmentFileWrapper : MCFileWrapper
{
    unsigned long long _attachmentSize;
    NSURL *_fileToCopy;
}

+ (id)localAttachmentFilesDirectory;
+ (id)fileWrapperWithURL:(id)arg1 andContentID:(id)arg2;
@property(retain, nonatomic) NSURL *fileToCopy; // @synthesize fileToCopy=_fileToCopy;
@property(nonatomic) unsigned long long approximateSize; // @synthesize approximateSize=_attachmentSize;
- (void).cxx_destruct;
- (BOOL)isALargeAttachment;
- (id)symbolicLinkDestinationURL;
- (id)archivedDataWithPartNumber:(id)arg1;
- (id)initWithDictionaryRepresentation:(id)arg1;

@end

