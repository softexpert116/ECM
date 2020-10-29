//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 25 2017 03:49:04).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "ComposeBackEnd.h"

#import "MFScriptingMessage-Protocol.h"

@class DOMHTMLDocument, EditableWebMessageDocumentWK1, NSArray, NSScriptObjectSpecifier, NSString;

@interface ComposeBackEndWK1 : ComposeBackEnd <MFScriptingMessage>
{
}

+ (id)composeBackEndsByUniqueID;
+ (void)unregisterComposeBackEnd:(id)arg1;
+ (void)registerComposeBackEnd:(id)arg1;
+ (id)composeBackEndForUniqueID:(id)arg1;
- (id)_copyOfContentsForDraft:(BOOL)arg1 isOkayToForceRichText:(BOOL)arg2 isMailDropPlaceholderMessage:(BOOL)arg3;
@property(readonly, nonatomic) DOMHTMLDocument *htmlDocumentForSave;
- (void)_recursivelyURLifyNode:(id)arg1;
- (void)addBaseURLTagToNode:(id)arg1;
- (id)_newPlainTextRepresentationIncludeAttachments:(BOOL)arg1;
- (id)htmlStringFromRange:(id)arg1 htmlDocument:(id)arg2 forDraft:(BOOL)arg3 convertObjectsToImages:(BOOL)arg4 convertEditableElements:(BOOL)arg5;
- (BOOL)containsRichText;
- (BOOL)hasContents;
- (void)_resizeAttachmentElementsForAttachments:(id)arg1;
- (void)getSignatureElement:(id *)arg1 parent:(id *)arg2 nextSibling:(id *)arg3;
- (BOOL)_mayUseDarkAppearance;
- (void)setupContentsForView:(id)arg1;
- (void)_initializeDocument;
- (void)setVcardPath:(id)arg1;
- (void)setHtmlContent:(id)arg1;
@property(readonly) NSScriptObjectSpecifier *objectSpecifier;
- (id)handleCloseScriptCommand:(id)arg1;
- (id)handleSendMessageCommand:(id)arg1;
- (id)handleSaveMessageCommand:(id)arg1;
- (void)replaceFormattedAddress:(id)arg1 withAddress:(id)arg2 forKey:(id)arg3;
- (void)removeFromBccRecipientsAtIndex:(unsigned long long)arg1;
- (void)removeFromCcRecipientsAtIndex:(unsigned long long)arg1;
- (void)removeFromToRecipientsAtIndex:(unsigned long long)arg1;
- (void)insertInBccRecipients:(id)arg1;
- (void)insertInBccRecipients:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)insertInCcRecipients:(id)arg1;
- (void)insertInCcRecipients:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)insertInToRecipients:(id)arg1;
- (void)insertInToRecipients:(id)arg1 atIndex:(unsigned long long)arg2;
- (void)insertRecipient:(id)arg1 atIndex:(unsigned long long)arg2 inHeaderWithKey:(id)arg3;
@property(readonly, copy, nonatomic) NSArray *bccRecipients;
@property(readonly, copy, nonatomic) NSArray *ccRecipients;
@property(readonly, copy, nonatomic) NSArray *toRecipients;
- (id)recipients;
- (void)_addRecipientsForKey:(id)arg1 toArray:(id)arg2;
- (void)setMessageSignature:(id)arg1;
- (id)messageSignature;
- (void)setContent:(id)arg1;
- (id)content;
- (void)setAppleScriptSubject:(id)arg1;
- (id)appleScriptSubject;
- (void)setAppleScriptSender:(id)arg1;
- (id)appleScriptSender;
- (void)setIsVisible:(BOOL)arg1;
- (BOOL)isVisible;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly, nonatomic) EditableWebMessageDocumentWK1 *document; // @dynamic document;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

