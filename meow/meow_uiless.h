#pragma once

class MeowTextService;

class MeowUILessManager :
	public ITfUIElement,
	public ITfCandidateListUIElement
{
public:
	MeowUILessManager(MeowTextService * _textservice);
	~MeowUILessManager();

	// IUnknown
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	// ITfUIElement
	HRESULT STDMETHODCALLTYPE GetDescription(BSTR *pbstrDescription);
	HRESULT STDMETHODCALLTYPE GetGUID(GUID *pguid);
	HRESULT STDMETHODCALLTYPE Show(BOOL bShow);
	HRESULT STDMETHODCALLTYPE IsShown(BOOL *pbShow);

	// ITfCandidateListUIElement
	HRESULT STDMETHODCALLTYPE GetUpdatedFlags(DWORD *pdwFlags);
	HRESULT STDMETHODCALLTYPE GetDocumentMgr(ITfDocumentMgr **ppdim);
	HRESULT STDMETHODCALLTYPE GetCount(UINT *puCount);
	HRESULT STDMETHODCALLTYPE GetSelection(UINT *puIndex);
	HRESULT STDMETHODCALLTYPE GetString(UINT uIndex,BSTR *pstr);
	HRESULT STDMETHODCALLTYPE GetPageIndex(UINT *pIndex, UINT uSize,UINT *puPageCnt);
	HRESULT STDMETHODCALLTYPE SetPageIndex(UINT *pIndex, UINT uPageCnt);
	HRESULT STDMETHODCALLTYPE GetCurrentPage(UINT *puPage);

private:
	ULONG reference;
	MeowTextService * textservice;

	BOOL shown;
};