//
//  HeadersEditor+ECMController.m
//  MailReceipt
//
//  Created by Gyorvari Gabor on 2016. 09. 16..
//  Copyright © 2016. Gyorvari Gabor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import "HeadersEditor+ECMController.h"
#import "HeadersEditor.h"
#import "ComposeBackEnd.h"
#import "ECMController.h"
#import "ComposeViewController.h"
//#import "NSObject+LPDynamicIvars.h"
#import "Constants.h"

@interface HeadersEditor_ECMController(MHNoImplementation)
//- (void)_subjectChanged;
//- (id)backEnd;
//- (id)originalMessageHeaders;
- (id)descendantsWithClassName:(NSString *)str;
- (id)htmlDocument;
- (id)originalMessage;
- (id)addressListForKey:(NSString *)key;
//- (void)setAddresses:(id)arg1;
- (id)mailAccount;
//- (id)firstEmailAddress;
- (id)emailAliases;
- (DOMDocumentFragment *)createDocumentFragmentWithMarkupString: (NSString *)str;

@end
NSString *AppleOriginalContents = @"AppleOriginalContents";
NSString *ApplePlainTextBody = @"ApplePlainTextBody";
NSMutableData *_responseData;
DOMHTMLDivElement *originalEmail;
NSString *alias, *genderStr;
NSString* greetStr = @"";
id document;

@implementation HeadersEditor_ECMController

- (void)MPPAwakeFromNib {
    
    
    
    [NSTimer scheduledTimerWithTimeInterval:0.3
    target:self
    selector:@selector(setHeaderInfo)
    userInfo:nil
    repeats:NO];
    
    [self MPPAwakeFromNib];
}
- (void)setHeaderInfo {
    id docEditor = [self valueForKey:@"_composeViewController"];
    int msgComposeType = [[docEditor valueForKey:@"_messageType"] intValue];
    
    // 1=Reply, 2=Reply All, 3=Forward, 4=Draft, 5=New
    switch (msgComposeType) {
        case 5:
            // new compose
            break;
        case 1:
            // reply
            break;
        case 3:
            // forward
            break;
        case 2:
            // reply all
            break;

        default:
            break;
    }
    ComposeBackEnd *backEnd = [docEditor backEnd];
    id mcMessageHeaders = [backEnd originalMessageHeaders];
//    id account = [self mailAccount];
    id fromAddress = [mcMessageHeaders addressListForKey:@"from"];
//    id toAddressList = [mcMessageHeaders addressListForKey:@"to"];
    alias = [self getAliasFromId:[fromAddress objectAtIndex:0]];

    document = [backEnd document];
//    NSString* body = [[[document htmlDocument] body] innerHTML];
    
    
    if ([[document htmlDocument] descendantsWithClassName:AppleOriginalContents] != NULL
        || [[document htmlDocument] descendantsWithClassName:AppleOriginalContents] != nil)
    {
        originalEmail=[[[document htmlDocument]
                        descendantsWithClassName:AppleOriginalContents] objectAtIndex:0];
    }
    else
    {
        originalEmail=[[[document htmlDocument]
                          descendantsWithClassName:ApplePlainTextBody] objectAtIndex:0];
    }
    
    if (originalEmail != nil) {
        if ([ECMController.userDefaults boolForKey:key_auto_greet] == YES) {
            
            if ([ECMController.userDefaults objectForKey:key_format_type] != nil) {
                NSInteger formatType = [ECMController.userDefaults integerForKey:key_format_type];
                
                if (formatType == 0) {
                    if ([ECMController.userDefaults objectForKey:key_custom_text] != nil) {
                        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_custom_text];
                        greetStr = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                    }
                } else if (formatType == 1) {
                    if ([ECMController.userDefaults objectForKey:key_random_text] != nil) {
                        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_random_text];
                        NSString* randStr = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                        if (randStr.length > 0) {
                            NSArray *stringArray = [randStr componentsSeparatedByString: @","];
                            greetStr = [ECMController selectRandomStringFromArray:stringArray];
                        }
                    }
                } else if  (formatType == 2) {
                    NSDate *time11, *time12, *time21, *time22, *time31, *time32;
                    NSString* timeStr1, *timeStr2, *timeStr3;
                    if ([ECMController.userDefaults objectForKey:key_time_val11] != nil) {
                        time11 = [ECMController.userDefaults objectForKey:key_time_val11];
                    }
                    if ([ECMController.userDefaults objectForKey:key_time_val12] != nil) {
                        time12 = [ECMController.userDefaults objectForKey:key_time_val12];
                    }
                    if ([ECMController.userDefaults objectForKey:key_time_text1] != nil) {
                        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text1];
                        timeStr1 = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                    }

                    if ([ECMController.userDefaults objectForKey:key_time_val21] != nil) {
                        time21 = [ECMController.userDefaults objectForKey:key_time_val21];
                    }
                    if ([ECMController.userDefaults objectForKey:key_time_val22] != nil) {
                        time22 = [ECMController.userDefaults objectForKey:key_time_val22];
                    }
                    if ([ECMController.userDefaults objectForKey:key_time_text2] != nil) {
                        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text2];
                        timeStr2 = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                    }

                    if ([ECMController.userDefaults objectForKey:key_time_val31] != nil) {
                        time31 = [ECMController.userDefaults objectForKey:key_time_val31];
                    }
                    if ([ECMController.userDefaults objectForKey:key_time_val32] != nil) {
                        time32 = [ECMController.userDefaults objectForKey:key_time_val32];
                    }
                    if ([ECMController.userDefaults objectForKey:key_time_text3] != nil) {
                        NSDictionary* dict = [ECMController.userDefaults objectForKey:key_time_text3];
                        timeStr3 = [dict valueForKey:GET_DEFAULT(ECMLanguageCode)];
                    }
                    
                    if (time11 != nil) {
                        NSDateFormatter *formatter_H = [[NSDateFormatter alloc] init];
                        [formatter_H setDateFormat:@"HH"];
                        NSDateFormatter *formatter_m = [[NSDateFormatter alloc] init];
                        [formatter_m setDateFormat:@"mm"];
                        NSDate* curDate = [NSDate date];
                        NSString *string_H = [formatter_H stringFromDate:curDate];
                        NSString *string_m = [formatter_m stringFromDate:curDate];
                        
                        if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time11] Minute2:[formatter_H stringFromDate:time11]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time12] Minute2:[formatter_H stringFromDate:time12]]) {
                            greetStr = timeStr1;
                        } else if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time21] Minute2:[formatter_H stringFromDate:time21]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time22] Minute2:[formatter_H stringFromDate:time22]]) {
                            greetStr = timeStr2;
                        } else { //if ([ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time31] Minute2:[formatter_H stringFromDate:time31]] && ![ECMController compareHour1:string_H Minute1:string_m Hour2:[formatter_H stringFromDate:time32] Minute2:[formatter_H stringFromDate:time32]]) {
                            greetStr = timeStr3;
                        }
                    }
                }
            }
            NSString* firstName = [self getFirstNameFromAlias:alias];
//            NSString* lastName = [self getLastNameFromAlias:alias];
//            [ECMController showAlertWithTitle:@"" Message:greetStr];
            
            [self getGenderFromUrl:@"https://my.mail-buddy.de/APIPanel/getGender/" firstName:firstName];
        }
        
    }

}
-(void)setECMReply {
    NSString* replyStr = @"<p>";
    NSString* mr = [ECMController localizedString:@"STRING_mr" localeIdentifier:GET_DEFAULT(ECMLanguageCode)];
    NSString* mrs = [ECMController localizedString:@"STRING_mrs" localeIdentifier:GET_DEFAULT(ECMLanguageCode)];

    if ([genderStr isEqualToString:@"Male"]) {
        replyStr = [replyStr stringByAppendingFormat:@"%@ %@ ", greetStr, mr];
    } else {
        replyStr = [replyStr stringByAppendingFormat:@"%@ %@ ", greetStr, mrs];
    }
    
    replyStr = [replyStr stringByAppendingFormat:@"%@", [self getLastNameFromAlias:alias]];
    replyStr = [replyStr stringByAppendingFormat:@"%@", @"</p>"];

    DOMDocumentFragment *headerFragment = [self createDocumentFragmentWithId:document Html:replyStr];
    DOMDocumentFragment *newLine = [self createDocumentFragmentWithId:document Html:@"<br/>"];
    [originalEmail insertBefore:headerFragment refChild: [originalEmail firstChild]];
    [originalEmail insertBefore:newLine refChild: [[originalEmail childNodes] item:1]];
}
-(void)getGenderFromUrl:(NSString*)url firstName:(NSString*)firstName {
    NSMutableURLRequest *theRequest=[NSMutableURLRequest requestWithURL:[NSURL URLWithString:[url stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]]
                                                            cachePolicy:NSURLRequestReloadIgnoringLocalCacheData
                                                        timeoutInterval:30.0];
    //do post request for parameter passing
    [theRequest setHTTPMethod:@"POST"];

    //set the content type to JSON
    [theRequest setValue:@"application/x-www-form-urlencoded" forHTTPHeaderField:@"Content-Type"];

    NSString *post = @"firstName=";
    post = [post stringByAppendingString:firstName];
    NSData *postData = [post dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    [theRequest setHTTPBody:postData];
    NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:theRequest delegate:self];
    
}
- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse *)response
{
    NSLog(@"Did Receive Response %@", response);
}
- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data
{
    //NSLog(@"Did Receive Data %@", data);
    id jsonData = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    NSString* msg = [jsonData objectForKey:@"msg"];
    
    NSData *genderData = [msg dataUsingEncoding:NSUTF8StringEncoding];
    id gender = [NSJSONSerialization JSONObjectWithData:genderData options:0 error:nil];
    genderStr = [gender objectForKey:@"gender"];

    [self setECMReply];
    
}
- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error
{
    NSLog(@"Did Fail");
    [ECMController showAlertWithTitle:@"" Message:error.description];
}
- (void)connectionDidFinishLoading:(NSURLConnection *)connection
{
    NSLog(@"Did Finish");
    // Do something with responseData
}

- (DOMDocumentFragment *)createDocumentFragmentWithId:(id)document Html:(NSString *)htmlString
{
    return [[document htmlDocument]
            createDocumentFragmentWithMarkupString:htmlString];
}

-(NSString*)getAliasFromId:(id)_id {
    NSString* alias;
    NSString* idStr = (NSString*)_id;
    if ([idStr rangeOfString:@"<"].location != NSNotFound) {
        int index = (int)[idStr rangeOfString:@"<"].location;
        alias = [idStr substringToIndex:index];
    }
    return alias;
}
-(NSString*)getFirstNameFromAlias:(NSString*)alias {
    NSArray *stringArray = [alias componentsSeparatedByString: @" "];
    if (stringArray != nil) {
        if ([stringArray count] > 0) {
            return [stringArray objectAtIndex:0];
        }
    }
    return nil;
}
-(NSString*)getLastNameFromAlias:(NSString*)alias {
    NSArray *stringArray = [alias componentsSeparatedByString: @" "];
    if (stringArray != nil) {
        if ([stringArray count] > 1) {
            return [stringArray objectAtIndex:[stringArray count]-2];
        } else {
            return alias;
        }
    }
    return nil;
}
-(void)getTimeSetting {
    
    
}
@end
